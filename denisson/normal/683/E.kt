import java.util.*

fun main(args: Array<String>) {
    val input = Scanner(System.`in`)
    val n = input.nextInt()
    var a = Array(1007, { i -> 0 })
    var ans = Array(1007, { i -> 0 })
    var was = Array(1007, { i -> 0 })
    for (i in 1..n)
        a[i] = input.nextInt()
    
    for (i in 1..n){
        var uk = -1
        for (j in 1..n)
            if (was[j] == 0 && uk == -1)
            {
                var ok = 0
                for (s in 1.. i - 1)
                    if (ans[s] > j)
                        ok += 1
                if (ok == a[j]){
                    if (uk == -1){
                        uk = j
                        break
                    }
                }
            }
        ans[i] = uk
        was[uk] = 1
    }
    
    for (i in 1..n){
        print(ans[i])
        print(' ')
    }
}