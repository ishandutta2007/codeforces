fun main(argv: Array<String>) {
    var aray = readLine()!!.split(" ").map{it.toInt()}.sorted()
    var a = aray[3]-aray[1]
    var b = aray[3]-aray[2]
    var c = aray[3]-aray[0]
    println("$a $b $c")
}