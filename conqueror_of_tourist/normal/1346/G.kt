private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)

fun main(args: Array<String>) {
    var (k, n) = readInts()
    var periods = readInts()
    var moments = readInts()
    
    var BIG = 1000010
    
    var factor = Array(BIG, {i -> -1})
    for (p in periods){
        var i = 0
        while (i < BIG){
            factor[i] = p
            i += p
        }
    }   
    
    var need = (n + 1)/2
    
    var i = 0
    var done = false
    total@ while (i < k && periods[i] * (need - 1) < 1000100 && !(done)){
        var p = periods[i]
        var map = HashMap<Int, Int>()
        for(v in moments){
            var modded = v % p
            if (modded !in map){
                map[modded] = 0
            }
            map[modded] = map[modded]!! + 1
        }
        
        for (modR in map.keys){
            var mod : Int = modR
            var count : Int = map.get(mod)!!
            if (count >= need && !(done)){
                var smallIn = 9999999
                var smallOut = 9999999
                for (v in moments){
                    if (v % p == mod && v < smallIn){
                        smallIn = v
                    }   
                    if (v % p != mod && v < smallOut){
                        smallOut = v
                    }
                }
                if (smallOut == 9999999){
                    println("YES")
                    print(smallIn)
                    print(" ")
                    println(p)
                    print(smallIn)
                    print(" ")
                    println(p)
                    done = true
                    break@total
                }
                else{
                    var g = 0
                    for (v in moments){
                        if (v % p != mod){
                            g = gcd(v - smallOut, g)
                        }
                    }
                    var gFactor = factor[g]
                    if (gFactor != -1){
                        println("YES")
                        print(smallIn)
                        print(" ")
                        println(p)
                        print(smallOut)
                        print(" ")
                        println(gFactor)
                        done = true
                        break@total
                    }
                }
            }
        }
        i += 1
    }
    if (!done){
        println("NO")
    }
}