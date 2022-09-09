import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.System.arraycopy
import java.lang.System.exit
import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.StringTokenizer
object H {
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
var tests = scanInt()
for (test in 0 until tests)
{
var n = scanInt()
var a = IntArray(n)
for (i in 0 until n)
{
a[i] = scanInt()
}
sort(a, n)
var curV = -1
var curCnt = 0
var maxV = -1
var maxCnt = 0
for (i in 0 until n)
{
if (a[i] != curV)
{
curV = a[i]
curCnt = 0
}
++curCnt
if (curCnt > maxCnt)
{
maxCnt = curCnt
maxV = curV
}
}
var toRemove = if (maxV == a[0] || maxV == a[n - 1]) maxCnt - (n - maxCnt + 1) else maxCnt - (n - maxCnt)
if (toRemove > 0)
{
var i:Int
i = 0
while (a[i] != maxV) {
i++
}
arraycopy(a, i + toRemove, a, i, n - i - toRemove)
n -= toRemove
}
out!!.println(n)
if (n % 2 == 0)
{
for (i in 0 until n / 2)
{
out!!.print("" + a[i + n / 2] + " ")
out!!.print("" + a[i] + " ")
}
}
else if (maxV == a[0])
{
for (i in 0 until n / 2)
{
out!!.print("" + a[i] + " ")
out!!.print("" + a[i + n / 2 + 1] + " ")
}
out!!.print("" + a[n / 2] + " ")
}
else
{
for (i in 0 until n / 2)
{
out!!.print("" + a[i + n / 2] + " ")
out!!.print("" + a[i] + " ")
}
out!!.print("" + a[n - 1] + " ")
}
out!!.println()
}
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
H.main(arrayOf())
}