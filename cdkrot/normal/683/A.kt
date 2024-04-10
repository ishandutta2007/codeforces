fun main(args: Array<String>) {
    val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
    if (border(a, x, y))
        println(1)
    else if (inside(a, x, y))
        println(0)
    else
        println(2)
}

fun inside(a: Int, x: Int, y: Int) = (0 <= x && x <= a && 0 <= y && y <= a)

fun border(a: Int, x: Int, y: Int) = inside(a, x, y) && (x == 0 || x == a || y == 0 || y == a)