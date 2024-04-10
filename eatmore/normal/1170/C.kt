import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.System.exit
import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.StringTokenizer
object C {
internal var `in`:BufferedReader? = null
internal var out:PrintWriter? = null
internal var tok:StringTokenizer? = null
@Throws(Exception::class)
internal fun solve() {
var tests = scanInt()
for (test in 0 until tests)
{
var s = scanString()
var t = scanString()
var bad = false
var i = 0
var j = 0
while (i < s.length || j < t.length)
{
if (i < s.length && j < t.length && s.get(i) == t.get(j))
{
++i
++j
continue
}
else if (i + 1 < s.length && j < t.length && s.get(i) == '-' && s.get(i + 1) == '-' && t.get(j) == '+')
{
i += 2
++j
continue
}
else
{
bad = true
break
}
}
out!!.println(if (bad) "NO" else "YES")
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
C.main(arrayOf())
}