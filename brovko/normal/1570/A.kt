fun main() 
{
    var t = readLine()!!.toInt()
    
    for(i in 0..t - 1)
    {
        var (a, b) = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        println(a + b)
    }
}