private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(){
    var(n:Int,k:Int)=readInts();
    while(k>0){
        if(n%10==0){
            n=n/10;
        }else{
            n=n-1;
        }
        k=k-1;
    }
    println(n);
}