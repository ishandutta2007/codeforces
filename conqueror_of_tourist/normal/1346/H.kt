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
    var (n, m) = readInts()
    
    var initSum = Array(n, {i -> 0})
    var initLen = Array(n, {i -> 0})
    
    for (i in 0 until n){
        var (l, r) = readInts()
        initSum[i] = l + r
        initLen[i] = r - l
    }
    
    var termSum = Array(m, {i -> 0})
    var termLen = Array(m, {i -> 0})
    
    var vBad = HashMap<Int, MutableList<Int>>()
    var bad = HashMap<Int, MutableList<Int>>()
    
    for (i in 0 until m){
        var (l, r) = readInts()
        termSum[i] = l + r
        termLen[i] = r - l
        if ((l + r) !in bad){
            bad[l + r] = mutableListOf<Int>()
            vBad[l + r] = mutableListOf<Int>()
        }
        bad[l + r]!!.add(r - l)
        vBad[l + r]!!.add(r - l)
    }
    
    for (v in bad.keys){
        bad[v]!!.sort()
    }
    
    for (i in 0 until n){
        var sum = initSum[i]
        var len = initLen[i]
        var out = -1;
        
        if (sum in bad.keys){
            var things = bad[sum]!!
            
            var ind = things.binarySearch(len + 1)
            var rInd = -(ind + 1)
            if (rInd == 0){
                out = -1
            }
            else{
                var care = things[rInd - 1]
                out = ((len - care)/2)
            }
        }
        
        if ((sum + 2) in bad.keys && (sum - 2) in bad.keys){
            var things1 = bad[sum + 2]!!
            var ind1 = things1.binarySearch(len - 1)
            var rInd1 = -(ind1 + 1)
            var out1 = -1;
            if (rInd1 == 0){
                out1 = -1
            }
            else{
                var care = things1[rInd1 - 1]
                out1 = ((len - care)/2)
            }
            
            var things2 = bad[sum - 2]!!
            var ind2 = things2.binarySearch(len - 1)
            var rInd2 = -(ind2 + 1)
            var out2 = -1;
            if (rInd2 == 0){
                out2 = -1
            }
            else{
                var care = things2[rInd2 - 1]
                out2 = ((len - care)/2)
            }
            
            if (out2 != -1 && out1 != -1){
                var outF = out1
                if (out2 > out1){
                    outF = out2
                }
                if (outF < out || out == -1){
                    out = outF
                }
            }
        }
        
        print(out)
        print(" ")
    }
}