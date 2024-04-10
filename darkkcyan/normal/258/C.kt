import kotlin.jvm.*
val mod = (1e9).toInt() + 7
data class modint(val x: Int = 0) {
    override fun toString() = x.toString()
    operator fun plus(o: Int) = (x + o).toModint()
    operator fun minus(o: Int) = (x - o).toModint()
    operator fun times(o: Int) = (x.toLong() * o).toModint()
    operator fun plus(o: modint) = this + o.x
    operator fun minus(o: modint) = this - o.x
    operator fun times(o: modint) = this * o.x
    fun sqr() = this * this
    fun pow(exp: Long): modint = 
        if (exp == 0L) 1.toModint()
        else if (exp == 1L) this
        else if (exp % 2 == 0L) this.pow(exp / 2).sqr()
        else this.pow(exp / 2).sqr() * this
    fun pow(exp: Int) = this.pow(exp.toLong())
    operator fun div(o: modint) = this * o.pow(mod - 2)
    operator fun div(o: Int) = this / o.toModint()
    operator fun compareTo(o: modint) = x.compareTo(o.x)
}
fun Int.toModint() = modint(if (this >= mod) this - mod else if (this < 0) this + mod else this)
fun String.toModint() = this.toInt().toModint()
fun Long.toModint() = (this % mod).toInt().toModint()

fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map{it.toInt()}.sorted()
    val max_val = 101010
    val cnt = IntArray(max_val)
    for (i in a) {
        cnt[i] ++
    }
    for (i in 1 until max_val) cnt[i] += cnt[i - 1]
    
    val divs = Array(max_val) { MutableList(0) { 0 } }
    for (i in 1 until max_val) {
        for (f in i until max_val step i) {
            divs[f].add(i)
        }
    }
    
    var ans = 1.toModint()  // for the case of all ones
    for (mx in 2 until max_val) {
        var exclude = 1.toModint()
        val cd = divs[mx]
        for (i in 0 until cd.size - 2) {
            exclude *= (i + 1).toModint().pow(cnt[cd[i + 1] - 1] - cnt[cd[i] - 1])
        }
        var all = exclude
        val u = cd.last()
        val v = cd[cd.size - 2]
        exclude *= (cd.size - 1).toModint().pow(n - cnt[v - 1])
        all *= (cd.size - 1).toModint().pow(cnt[u - 1] - cnt[v - 1])
        all *= cd.size.toModint().pow(n - cnt[u - 1])
        val cur_ans = all - exclude
        // if (mx <= 20) { 
            // System.err.println("mx = $mx, cur_ans = $cur_ans, all = $all, exclude = $exclude") 
        // } 
        ans += cur_ans
    }
    println(ans)
}