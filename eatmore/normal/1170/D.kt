import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.System.arraycopy
import java.lang.System.exit
import java.util.Arrays.copyOf
import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.ArrayDeque
import java.util.NoSuchElementException
import java.util.Queue
import java.util.StringTokenizer
object D {
internal var `in`:BufferedReader? = null
internal var out:PrintWriter? = null
internal var tok:StringTokenizer? = null
internal class IntList {
var data = IntArray(3)
var size = 0
fun size():Int {
return size
}
fun get(index:Int):Int {
if (index < 0 || index >= size)
{
throw IndexOutOfBoundsException()
}
return data[index]
}
fun clear() {
size = 0
}
fun set(index:Int, value:Int) {
if (index < 0 || index >= size)
{
throw IndexOutOfBoundsException()
}
data[index] = value
}
fun expand() {
if (size >= data.size)
{
data = copyOf(data, (data.size shl 1) + 1)
}
}
fun insert(index:Int, value:Int) {
if (index < 0 || index > size)
{
throw IndexOutOfBoundsException()
}
expand()
arraycopy(data, index, data, index + 1, size++ - index)
data[index] = value
}
fun delete(index:Int):Int {
if (index < 0 || index >= size)
{
throw IndexOutOfBoundsException()
}
var value = data[index]
arraycopy(data, index + 1, data, index, --size - index)
return value
}
fun push(value:Int) {
expand()
data[size++] = value
}
fun pop():Int {
if (size == 0)
{
throw NoSuchElementException()
}
return data[--size]
}
fun unshift(value:Int) {
expand()
arraycopy(data, 0, data, 1, size++)
data[0] = value
}
fun shift():Int {
if (size == 0)
{
throw NoSuchElementException()
}
var value = data[0]
arraycopy(data, 1, data, 0, --size)
return value
}
}
@Throws(Exception::class)
internal fun solve() {
var m = scanInt()
var a = IntArray(m)
var n = 0
for (i in 0 until m)
{
a[i] = scanInt()
if (a[i] < 0)
{
++n
}
}
var r = arrayOfNulls<IntList>(n)
var q = ArrayDeque<IntList>()
for (i in 0 until n)
{
r[i] = IntList()
q.add(r[i])
}
for (i in 0 until m)
{
var cur = q.remove()
if (a[i] >= 0)
{
cur.push(a[i])
q.add(cur)
}
}
out!!.println(n)
for (l in r)
{
out!!.print(l!!.size)
for (i in 0 until l!!.size)
{
out!!.print(" " + l!!.data[i])
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
D.main(arrayOf())
}