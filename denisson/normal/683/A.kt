fun main(args: Array<String>) {
    val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
    if (x > 0 && x < a && y > 0 && y < a)
        print(0)
    else
    {
        if ( (x <= a) && (y <= a) && (x >= 0) && (y >= 0) && ( (x == a) || (y == a) || (y == 0) || (x == 0)) )
           print(1)
        else
           print(2)
    }
}