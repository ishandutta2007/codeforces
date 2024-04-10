fun main(){
   var t = readLine()!!.toInt()
   for (i in 1..t){
   var n = readLine()!!.toLong()
   if (n < 1000){
        println(n)
   }
   if (n >= 1000 && n < 999500){
        print((n + 500) / 1000)
        println('K');
   }
   if (n >= 999500){
        print((n + 500000) / 1000000)
        println('M');
   }
   }
}