fun main(){
    val n = readLine()!!.toInt()
    for (i in 1..n){
        val i = readLine()!!.toInt()
        if (i < 1000){
            println(i)
        }
        else{
        if (i < 999500){
            val j = (i + 500)/1000
            println(j.toString()+"K")
        }
        else{
            val j = (i + 500000)/1000000
            println(j.toString()+"M")
        }
        }
    }
}