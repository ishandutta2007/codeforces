import java.util.Scanner
 
fun main(args: Array<String>) {
    val input = Scanner(System.`in`)
    val t = input.nextLine().toInt()
 
    for (x in 0 until t) {
        var (N, a,b) = input.nextLine().split(' ').map { it.toInt() }
        var k=input.nextLine()
        var prec=0
        var sol=0
        for(i in 0 until N){
            if(k[i]=='0'){
                prec=0
            }else{
                if(prec+a<=b){
                    prec=a
                    sol+=a
                }else{
                    sol+=b-prec
                    prec=b-prec
                }
            }
        }
        println(sol)
    }
}