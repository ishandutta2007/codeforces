fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        readLine()!!.toInt()
        val a = readLine()!!.split(' ').map{it.toInt()}.withIndex().sortedBy {it.value}
        if (a[0].value == a[1].value) {
            println(a.last().index + 1)
        } else {
            println(a[0].index + 1)
        }
        
    }
}