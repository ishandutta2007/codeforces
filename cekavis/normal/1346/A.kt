fun main(args: Array<String>) {
    var T = readLine()!!.toInt()
    while (T-->0){
        var (n, k) = readLine()!!.split(' ').map { it.toInt() }
        n=n/(((k+1)*k+1)*k+1)
        println("$n ${n*k} ${n*k*k} ${n*k*k*k}")
    }
}