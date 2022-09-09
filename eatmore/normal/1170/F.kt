import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.Math.min
import java.lang.System.exit
import java.util.Arrays.binarySearch
import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.StringTokenizer
object F {
internal var `in`:BufferedReader? = null
internal var out:PrintWriter? = null
internal var tok:StringTokenizer? = null
internal fun sort(a:IntArray, n:Int) {
if (n == 0)
{
return
}
for (i in 1 until n)
{
var j = i
var ca = a[i]
do
{
var nj = (j - 1) shr 1
var na = a[nj]
if (ca <= na)
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
j += if ((a[j + 2] > a[j + 1])) 2 else 1
}
if ((j shl 1) + 2 == i)
{
j = (j shl 1) + 1
}
var na = a[i]
a[i] = ca
ca = na
while (j != 0 && a[j] < ca)
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
@Throws(Exception::class)
internal fun solve() {
var n = scanInt()
var m = scanInt()
var k = scanInt()
var a = IntArray(n)
for (i in 0 until n)
{
a[i] = scanInt()
}
sort(a, n)
var `as` = LongArray(n + 1)
for (i in 0 until n)
{
`as`[i + 1] = `as`[i] + a[i]
}
var ans = java.lang.Long.MAX_VALUE
for (i in 0..n - m)
{
var v = a[i + m / 2]
var up = v.toLong() * (m / 2).toLong() - (`as`[i + m / 2] - `as`[i])
if (up <= k)
{
var down = (`as`[i + m] - `as`[i + m / 2]) - v.toLong() * (m - m / 2).toLong()
ans = min(ans, up + down)
}
else
{
var l = a[i]
var r = v
while (l + 1 < r)
{
v = (l + r) / 2
var p = binarySearch(a, i, i + m, v)
if (p < 0)
{
p = p.inv()
}
up = v.toLong() * (p - i).toLong() - (`as`[p] - `as`[i])
if (up <= k)
{
l = v
}
else
{
r = v
}
}
v = l
var p = binarySearch(a, i, i + m, v)
if (p < 0)
{
p = p.inv()
}
up = v.toLong() * (p - i).toLong() - (`as`[p] - `as`[i])
var down = (`as`[i + m] - `as`[p]) - v.toLong() * (i + m - p).toLong()
ans = min(ans, up + down)
}
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
F.main(arrayOf())
}