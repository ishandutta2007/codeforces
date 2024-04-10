import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.System.exit
import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.StringTokenizer
object B {
internal var `in`:BufferedReader? = null
internal var out:PrintWriter? = null
internal var tok:StringTokenizer? = null
@Throws(Exception::class)
internal fun solve() {
var n = scanInt()
var ans = 0
var v1 = 0
var v2 = 0
for (i in 0 until n)
{
var a = scanInt()
if (v2 > a)
{
++ans
}
else if (a > v1)
{
v2 = v1
v1 = a
}
else if (a > v2)
{
v2 = a
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
B.main(arrayOf())
}