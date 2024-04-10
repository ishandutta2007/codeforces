import java.io.*
import java.util.*
 
fun min(a:Double,b:Double) = if (a<b) a else b
fun max(a:Double,b:Double) = if (a>b) a else b
fun min(a:Long,b:Long) = if (a<b) a else b
fun max(a:Long,b:Long) = if (a>b) a else b
 
var cin: BufferedReader? = null
var cout: PrintWriter? = null
var tok = StringTokenizer("")
fun init() {
    Locale.setDefault(Locale.US)
    cin = BufferedReader(InputStreamReader(System.`in`))
    cout = PrintWriter(System.`out`)
}
 
var nul=0.toLong();
var one=1.toLong();
var two=2.toLong();
var three=3.toLong();
var four=4.toLong();
var five=5.toLong();
fun powmod(a:Long,b:Long,mod:Long):Long {
 
    if (b==1.toLong()) return a;
    var k=powmod(a,b/2,mod);
    if (b%2==0.toLong())
    { return (k*k)%mod }
    else { k=k*k; k=k%mod; k=k*a; k=k%mod; return k; }
}
fun prime (p:Long):Long {
    if (p==one) return 0.toLong();
    var i=two;
    while (i*i<=p) {if (p%i==nul) return i; i++; }
    return one;
}
fun inv (a:Long,mod:Long):Long {
return powmod(a,mod-2,mod);
}
 
fun readString(): String {
    while (!tok.hasMoreTokens()) {
        tok = StringTokenizer(cin!!.readLine())
    }
    return tok.nextToken()
}
 
 
fun readInt() = readString().toInt()
 
fun readIntArray(size: Int) = Array(size, { i -> readInt() })
 
fun readLong() = readString().toLong()
fun readLongArray(size: Long) = Array(size.toInt(), { i -> readLong() })
fun readLn():String = readLine()!!.toString()
fun readLongs()  = readLn().split(" ").map{it.toLong()}
fun solve() {
 
 
    /*
    var map=hashMapOf<String,Int>();
    map[q] <=> map.getOrDefault(q,0)
       - k=v.sortedWith(compareBy({it.first},{it.second}));
    prLong("${k[i].second}"); -   
    var m=ArrayList<Long> (); <=> vector
    getline(cin,a) <=> readLine()!!.last()
   readLong() -  
   readLongs() -  
   readLine()!!.toCharArray() -     
 
    */
    /* --------- */
        //    
        var q=readLongArray(four);
    q.sort();
    print(q[3]-q[0]); print(" ");print(q[3]-q[1]); print(" ");print(q[3]-q[2]); print(" ");
 
    /* --------- */
 
}
 
fun main() {
    init();
 
    var T=one;
    //T=readLong();
    for (i55555 in 1..T) solve()
}