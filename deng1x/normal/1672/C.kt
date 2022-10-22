
fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()!!.toInt()
        val a = readLine()!!.split(" ").map { it.toInt() }

        if ((0 until (a.size - 1)).count { a[it] == a[it + 1] } <= 1) {
            println(0)
            return@repeat
        }

        val first = (0 until (a.size - 1)).first { a[it] == a[it + 1]  }
        val last = (0 until (a.size - 1)).last { a[it] == a[it + 1]  }
        if (first + 1 == last) {
            println(1)
            return@repeat
        }
        println(last - first - 1)
    }
}