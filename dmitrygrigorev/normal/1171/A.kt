fun main(){
    val t = readLine()!!.toInt()
    for (i in 1..t){
        val n = readLine()!!.toInt()
        for (j in 1..1000){
            if (j <= n && 6*j >= n){
                println(j)
                break
            }
        }
    }
}