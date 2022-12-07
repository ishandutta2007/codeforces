import java.util.*
private fun readInt() = readLine()!!.toInt()
private fun readStrings() = readLine()!!.split(" ")
private fun readInts() = readStrings().map{it.toInt()}
private fun readLongs() = readStrings().map{it.toLong()}

fun main() {
    var m = readInt()
    var cypher = readInts()
    var n = cypher.count { it == -1 }
    val org = Array(n) {ArrayList<Int>()}
    val idx = LinkedList<Int>((0 until n).toList())
    var it = idx.iterator()
    for (x in cypher) {
        if (!it.hasNext())
            it = idx.iterator()
        val i = it.next()
        if (x == -1) {
            it.remove()
        }
        else {
            org[i].add(x)
//            if (x == -1)
//                println("${i} ${x}")
        }
    }
    println(n)
    println(org.joinToString("\n"){"${it.size} ${it.joinToString(" ")}"})
}