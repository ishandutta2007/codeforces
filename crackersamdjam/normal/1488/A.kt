fun main(args: Array<String>){
    repeat(readLine()!!.toInt()){
        var (x, y) = readLine()!!.split(" ").map { it.toInt() }
        var ans = y%x
        y /= x;
        while(y > 0){
            ans += y%10
            y /= 10
        }
        println(ans)
    }
}