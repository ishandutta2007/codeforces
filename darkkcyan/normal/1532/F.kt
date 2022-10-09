fun main() {
    val n = readLine()!!.toInt()
    val s = Array(2 * n - 2) { readLine()!! }

    val mxLength = ArrayList<Int>()
    for ((i, cur_s) in s.withIndex()) {
        if (cur_s.length == n - 1) {
            mxLength.add(i)
        }
    }

    assert(mxLength.size == 2)

    fun check(prefId: Int, suffId: Int): String? {
        var ans = ""
        val pref = s[prefId]
        val suff = s[suffId]
        val picked_pref = BooleanArray(n);
        val picked_suff = BooleanArray(n)
        for (cur_s in s) {
            if (pref.startsWith(cur_s) && !picked_pref[cur_s.length]) {
                picked_pref[cur_s.length] = true
                ans += "P"
                continue
            }
            if (suff.endsWith(cur_s) && !picked_suff[cur_s.length]) {
                picked_suff[cur_s.length] = true
                ans += 'S'
                continue
            }
            return null
        }
        return ans
    }

    var ans = check(mxLength[0], mxLength[1]) ?: check(mxLength[1], mxLength[0])
    println(ans!!)
}