import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.System.exit
import java.util.Arrays.binarySearch
import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.StringTokenizer
object E {
internal var `in`:BufferedReader? = null
internal var out:PrintWriter? = null
internal var tok:StringTokenizer? = null
@Throws(Exception::class)
internal fun solve() {
var n = scanInt()
var m = scanInt()
var a = IntArray(n + 1)
for (i in 0 until n)
{
a[i + 1] = a[i] + scanInt()
}
var q = scanInt()
for (qq in 0 until q)
{
var c = scanInt()
var pos = 0
var prev = -1
for (i in 0 until c)
{
var cur = scanInt() - 1
pos += cur - prev - 1
var p = binarySearch(a, pos)
if (p < 0)
{
p = p.inv() - 1
}
pos = a[p]
prev = cur
}
out!!.println(if (a[n] - pos <= m - prev - 1) "YES" else "NO")
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
E.main(arrayOf())
}