#include <bits/stdc++.h>
using namespace std;

// Yes, I do it as a joke.
// But I square, doing this is harder than normal C++.
// (Maybe I'm a masochist???)

#define s_nguyn int
#define di long
#define ch char
#define u_ra cout
#define u_vo cin
#define chnh main
#define nu if
#define ngc_li else
#define lp for
#define trong_khi while
#define thc hin do
#define tip_tc continue
#define ngn break
#define tr_v return
#define cu_trc struct
#define t_ng auto
#define ng_b_vi_io_chun sync_with_stdio
#define buc tie
#define ng true
#define sai false
#define hng const 
#define vec_t vector
#define tp_hp set
#define nh_x map
#define xu string

s_nguyn chnh() {
    u_vo.buc(0)->ng_b_vi_io_chun(sai);
    
    nh_x<xu, s_nguyn> t_in;
    s_nguyn th_t = 0;
    lp(ch u = 'a'; u <= 'z'; ++u) {
        lp(ch ui = 'a'; ui <= 'z'; ++ui) {
            nu (u == ui) tip_tc;
            t_in[xu() + u + ui] = ++th_t;
        }
    }
    
    s_nguyn s_test;
    u_vo >> s_test;
    
    trong_khi(s_test --) {
        xu t;
        u_vo >> t;
        u_ra << t_in[t] << '\n';
    }
    
    tr_v 0;
}