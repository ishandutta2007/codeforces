import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.Math.max
import java.lang.Math.min
import java.lang.System.exit
import java.util.Arrays.binarySearch
import java.util.Arrays.fill
import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.StringTokenizer
object I {
internal var MOD = 998244353
internal var `in`:BufferedReader? = null
internal var out:PrintWriter? = null
internal var tok:StringTokenizer? = null
internal fun indices(n:Int):IntArray {
var r = IntArray(n)
for (i in 0 until n)
{
r[i] = i
}
return r
}
internal fun sortBy(a:IntArray, n:Int, v:IntArray) {
if (n == 0)
{
return
}
for (i in 1 until n)
{
var j = i
var ca = a[i]
var cv = v[ca]
do
{
var nj = (j - 1) shr 1
var na = a[nj]
if (cv <= v[na])
{
break
}
a[j] = na
j = nj
}
while (j != 0)
a[j] = ca
}
var ca = a[0]
for (i in n - 1 downTo 1)
{
var j = 0
while ((j shl 1) + 2 + Integer.MIN_VALUE < i + Integer.MIN_VALUE)
{
j = j shl 1
j += if ((v[a[j + 2]] > v[a[j + 1]])) 2 else 1
}
if ((j shl 1) + 2 == i)
{
j = (j shl 1) + 1
}
var na = a[i]
a[i] = ca
ca = na
var cv = v[ca]
while (j != 0 && v[a[j]] < cv)
{
j = (j - 1) shr 1
}
while (j != 0)
{
na = a[j]
a[j] = ca
ca = na
j = (j - 1) shr 1
}
}
a[0] = ca
}
internal fun sortedIndices(n:Int, v:IntArray):IntArray {
var r = indices(n)
sortBy(r, n, v)
return r
}
internal fun addMod(a:Int, b:Int):Int {
var res = a + b
return if (res >= MOD) res - MOD else res
}
internal fun mulMod(a:Int, b:Int):Int {
var res = (a.toLong() * b % MOD).toInt()
return if (res < 0) res + MOD else res
}
internal class Tree(n:Int) {
var n:Int = 0
var t:IntArray
var m:IntArray
init{
this.n = n
t = IntArray(2 * n - 1)
m = IntArray(n - 1)
fill(m, 1)
}
fun fix(i:Int) {
t[i - 1] = mulMod(m[i - 1], addMod(t[(i shl 1) - 1], t[i shl 1]))
}
fun push(i:Int) {
for (j in 31 - Integer.numberOfLeadingZeros(i) downTo 1)
{
var p = i shr j
var v = m[p - 1]
if (v != 1)
{
if (p shl 1 < n)
{
m[(p shl 1) - 1] = mulMod(m[(p shl 1) - 1], v)
}
t[(p shl 1) - 1] = mulMod(t[(p shl 1) - 1], v)
if ((p shl 1) + 1 < n)
{
m[p shl 1] = mulMod(v, m[p shl 1])
}
t[p shl 1] = mulMod(t[p shl 1], v)
m[p - 1] = 1
}
}
}
fun get(ii:Int):Int {
var i = ii
i += n
var v = t[i - 1]
i = i shr 1
while (i != 0)
{
v = mulMod(v, m[i - 1])
i = i shr 1
}
return v
}
fun getSum(ll:Int, rr:Int):Int {
var l = ll
var r = rr
var vl = 0
var vr = 0
l += n
r += n
while (true)
{
if (vl != 0 && l != 1)
{
vl = mulMod(vl, m[l - 2])
}
if (vr != 0)
{
vr = mulMod(vr, m[r - 1])
}
if (l == r && (l and 1) != 0)
{
break
}
if ((l and 1) != 0)
{
vl = addMod(vl, t[l - 1])
l++
}
if ((r and 1) != 0)
{
--r
vr = addMod(vr, t[r - 1])
}
l = l ushr 1
r = r ushr 1
}
var v = addMod(vl, vr)
l = l ushr 1
while (l != 0)
{
v = mulMod(v, m[l - 1])
l = l ushr 1
}
return v
}
fun set(ii:Int, v:Int) {
var i = ii
i += n
push(i)
t[i - 1] = v
i = i shr 1
while (i != 0)
{
fix(i)
i = i shr 1
}
}
fun mulBy(ll:Int, rr:Int, v:Int) {
var l = ll
var r = rr
if (l == r)
{
return
}
l += n
r += n
var cl = l
var cr = r
while (cl != cr)
{
if ((cl and 1) != 0)
{
if (cl < n)
{
m[cl - 1] = mulMod(v, m[cl - 1])
}
t[cl - 1] = mulMod(v, t[cl - 1])
cl++
}
if ((cr and 1) != 0)
{
--cr
if (cr < n)
{
m[cr - 1] = mulMod(v, m[cr - 1])
}
t[cr - 1] = mulMod(t[cr - 1], v)
}
cl = cl ushr 1
cr = cr ushr 1
}
run({ var i = Integer.numberOfTrailingZeros(l) + 1
while (l.ushr(i) != 0)
{
fix(l.ushr(i))
++i
} })
var i = Integer.numberOfTrailingZeros(r) + 1
while (r.ushr(i) != 0)
{
fix(r.ushr(i))
++i
}
}
}
@Throws(Exception::class)
internal fun solve() {
var n = scanInt()
var l = IntArray(n)
var r = IntArray(n)
for (i in 0 until n)
{
l[i] = 2 * scanInt()
r[i] = 2 * scanInt() + 1
}
var idx = sortedIndices(n, l)
var vl = IntArray(n)
var vr = IntArray(n)
var vn = 0
var maxR = -1
for (i in 0 until n)
{
if (i == 0 || l[idx[i]] != l[idx[i - 1]])
{
vl[vn] = l[idx[i]]
vr[vn] = min(vl[vn], maxR)
vn++
}
maxR = max(maxR, r[idx[i]])
}
var dyn = Tree(vn)
dyn.set(0, 1)
var ans = 0
for (i in idx)
{
ans = addMod(ans, ans)
var cl = binarySearch(vl, 0, vn, l[i])
if (cl < 0)
{
cl = cl.inv() - 1
}
var cr = binarySearch(vr, 0, vn, r[i])
if (cr < 0)
{
cr = cr.inv() - 1
}
var v = dyn.getSum(cl, cr + 1)
if (r[i] == maxR)
{
ans = addMod(ans, v)
}
else
{
dyn.set(cr, addMod(dyn.get(cr), v))
}
dyn.mulBy(cr + 1, vn, 2)
}
out!!.print(ans)
}
@Throws(IOException::class)
internal fun scanInt():Int {
return parseInt(scanString())
}
@Throws(IOException::class)
internal fun scanLong():Long {
return parseLong(scanString())
}
@Throws(IOException::class)
internal fun scanString():String {
while (tok == null || !tok!!.hasMoreTokens())
{
tok = StringTokenizer(`in`!!.readLine())
}
return tok!!.nextToken()
}
@JvmStatic fun main(args:Array<String>) {
try
{
`in` = BufferedReader(InputStreamReader(System.`in`))
out = PrintWriter(System.out)
solve()
`in`!!.close()
out!!.close()
}
catch (e:Throwable) {
e.printStackTrace()
exit(1)
}
}
}
fun main() {
I.main(arrayOf())
}