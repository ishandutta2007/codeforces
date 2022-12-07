fun main(args: Array<String>) {
    val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
    var flag1:Int = 0
    var flag2:Int = 0
    if(0 < x && x < a) flag1 = 1
    
    if(0 == x || x == a) flag1 = -1
    
    if(0 < y && y < a) flag2 = 1
    
    if(0 == y || y == a) flag2 = -1
    if(flag1 == 1 && flag2 == 1) println(0)
    else if(flag1 != 0 && flag2 != 0) println(1);
    else println(2)
}