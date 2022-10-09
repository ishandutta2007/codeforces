fun main() {
    for (i in 1 .. readLine()!!.toInt()) {
        println(readLine()!!.split(' ').map(String::toInt).reduce{ u, v -> u + v })
    }
}