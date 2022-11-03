fun main(args: Array<String>) { 
    var s = readLine()!!.split(' ').map(String::toInt)
    var mas = s.toList()
    var s2 = readLine()!!.split(' ').map(String::toInt)
    var mas2 = s2.toList()
    var ans = Array(2007, { i -> 0 })
    var k : Int = 0
    for (i in 1..(mas.size-1)){
        var f : Int = 0
        for (j in 1..(mas2.size-1)){
            if (mas2[j] == mas[i])
                f = 1
        }
        if (f == 0){
            k += 1
            ans[k] = mas[i]
        }
    }
    
    
    for (i in 1..(mas2.size-1)){
        var f : Int = 0
        for (j in 1..(mas.size-1)){
            if (mas[j] == mas2[i])
                f = 1
        }
        if (f == 0){
            k += 1
            ans[k] = mas2[i]
        }
    }
    
    print(k)
    print(' ')
    for (i in 1..k){
        print(ans[i])
        print(' ')
    }
}