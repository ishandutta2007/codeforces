fun main() {
    readLine()!!
    val a = readLine()!!.split(' ').map { it.toLong() }.withIndex().sortedBy {it.value}.reversed()
    
    val cost = a.foldIndexed(0L) { id, s, v -> s + id * v.value + 1 }
    println(cost)
    println(a.map { it.index + 1 }.joinToString(" "))
}