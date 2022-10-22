private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val t=readInt();
    for(x in 0 until t){
        val k=readLn();
        var ans=0;
        var bo=0;
        for(a in 0 until k.length){
        val y=k[a];
            if(y=='>'){
                if(ans>=0){
                    ans=+10;
                }else{
                    bo=1;
                }
            }
            if(y=='<'){
                if(ans<=0){
                    ans=-10;
                }else{
                    bo=1;
                }
            }
            if(y=='='){
                
            }
        }
        if(bo==1){
            println("?");
        }else{
            if(ans==0){
                println("=");
            }
            if(ans<0){
                println("<");
            }
            if(ans>0){
                println(">");
            }
        }
        
    }
}