fun main(){
    val a = readLine()!!.split(' ').map {it.toInt()}
    val b = a.sorted()
    println(b[3] - b[0])
    println(b[3] - b[1])
    println(b[3] - b[2])
}