fun main() {
    val (n, m) = readLine()!!.split(" ").map {it.toInt()}
    println((0 until n).map { i ->
        readLine()!!.toCharArray().mapIndexed { f, ch ->
            if (ch == '-') ch
            else if ((i + f) % 2 == 0) 'B'
            else 'W'
        }.joinToString("")
    }.joinToString("\n"))
}