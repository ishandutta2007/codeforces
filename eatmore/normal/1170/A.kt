import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.System.exit
import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.StringTokenizer
object A {
internal var `in`:BufferedReader? = null
internal var out:PrintWriter? = null
internal var tok:StringTokenizer? = null
@Throws(Exception::class)
internal fun solve() {
var tests = scanInt()
for (test in 0 until tests)
{
var x = scanInt()
var y = scanInt()
if (x > y)
{
var t = x
x = y
y = t
}
out!!.println("1 " + (x - 1) + " " + (y - x + 1))
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
A.main(arrayOf())
}