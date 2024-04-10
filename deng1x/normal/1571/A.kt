fun main() {
    repeat(readLine()!!.toInt()) {
        val line = readLine()!!
        when {
            line.all { it == '=' } -> println("=")
            line.all { it == '=' || it == '>' } -> println(">")
            line.all { it == '=' || it == '<' } -> println("<")
            else -> println("?")
        }
    }
}