/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int i; cin >> i;
    if (i == 1) cout << 1;
    if (i == 2) cout << 9;
    if (i == 3) cout << 245;
    if (i == 4) cout << 126565;
    if (i == 5) cout << 54326037;
    if (i == 6) cout << 321837880;
    if (i == 7) cout << 323252721;
    if (i == 8) cout << 754868154;
    if (i == 9) cout << 328083248;
    if (i == 10) cout << 838314395;
    if (i == 11) cout << 220816781;
    if (i == 12) cout << 893672292;
    if (i == 13) cout << 166441208;
    if (i == 14) cout << 251255697;
    if (i == 15) cout << 114256285;
    if (i == 16) cout << 118775501;
    if (i == 17) cout << 482714697;
    if (i == 18) cout << 11784725;
    if (i == 19) cout << 460862131;
    if (i == 20) cout << 550384565;
    if (i == 21) cout << 106742050;
    if (i == 22) cout << 425241115;
    if (i == 23) cout << 626692854;
    if (i == 24) cout << 674266678;
    if (i == 25) cout << 320014275;
    if (i == 26) cout << 345949512;
    if (i == 27) cout << 527320049;
    if (i == 28) cout << 897822749;
    if (i == 29) cout << 137190263;
    if (i == 30) cout << 491039182;
    if (i == 31) cout << 810384961;
    if (i == 32) cout << 482023334;
    if (i == 33) cout << 658099864;
    if (i == 34) cout << 886790989;
    if (i == 35) cout << 845381174;
    if (i == 36) cout << 371433224;
    if (i == 37) cout << 278969124;
    if (i == 38) cout << 420088324;
    if (i == 39) cout << 696766322;
    if (i == 40) cout << 388302635;
    if (i == 41) cout << 141033366;
    if (i == 42) cout << 46387851;
    if (i == 43) cout << 932125021;
    if (i == 44) cout << 278342766;
    if (i == 45) cout << 371131134;
    if (i == 46) cout << 922501918;
    if (i == 47) cout << 110778457;
    if (i == 48) cout << 506223573;
    if (i == 49) cout << 806353719;
    if (i == 50) cout << 391845991;
    if (i == 51) cout << 923507761;
    if (i == 52) cout << 780307355;
    if (i == 53) cout << 109951115;
    if (i == 54) cout << 830090230;
    if (i == 55) cout << 605558495;
    if (i == 56) cout << 344686604;
    if (i == 57) cout << 988110893;
    if (i == 58) cout << 944684429;
    if (i == 59) cout << 715019947;
    if (i == 60) cout << 799898820;
    if (i == 61) cout << 384672708;
    if (i == 62) cout << 907325090;
    if (i == 63) cout << 758952329;
    if (i == 64) cout << 550672104;
    if (i == 65) cout << 368337206;
    if (i == 66) cout << 394915145;
    if (i == 67) cout << 401744167;
    if (i == 68) cout << 923781939;
    if (i == 69) cout << 831857516;
    if (i == 70) cout << 407845661;
    if (i == 71) cout << 329267374;
    if (i == 72) cout << 927004007;
    if (i == 73) cout << 891609656;
    if (i == 74) cout << 897919613;
    if (i == 75) cout << 481297880;
    if (i == 76) cout << 737337940;
    if (i == 77) cout << 651873737;
    if (i == 78) cout << 287246681;
    if (i == 79) cout << 973133651;
    if (i == 80) cout << 679864988;
    if (i == 81) cout << 784719328;
    if (i == 82) cout << 820504764;
    if (i == 83) cout << 875613823;
    if (i == 84) cout << 806512665;
    if (i == 85) cout << 164851642;
    if (i == 86) cout << 500228957;
    if (i == 87) cout << 951814419;
    if (i == 88) cout << 447763649;
    if (i == 89) cout << 273141670;
    if (i == 90) cout << 979349615;
    if (i == 91) cout << 964027956;
    if (i == 92) cout << 809510400;
    if (i == 93) cout << 276634497;
    if (i == 94) cout << 116631976;
    if (i == 95) cout << 426739449;
    if (i == 96) cout << 175282420;
    if (i == 97) cout << 885948162;
    if (i == 98) cout << 62270880;
    if (i == 99) cout << 974395255;
    if (i == 100) cout << 675165056;
    if (i == 101) cout << 759589968;
    if (i == 102) cout << 837957573;
    if (i == 103) cout << 931897605;
    if (i == 104) cout << 152352780;
    if (i == 105) cout << 585420109;
    if (i == 106) cout << 1772087;
    if (i == 107) cout << 333401718;
    if (i == 108) cout << 898833639;
    if (i == 109) cout << 745874265;
    if (i == 110) cout << 786209423;
    if (i == 111) cout << 691982338;
    if (i == 112) cout << 498790927;
    if (i == 113) cout << 473374639;
    if (i == 114) cout << 274302623;
    if (i == 115) cout << 971280670;
    if (i == 116) cout << 241671319;
    if (i == 117) cout << 13070005;
    if (i == 118) cout << 302088807;
    if (i == 119) cout << 550276351;
    if (i == 120) cout << 436592588;
    if (i == 121) cout << 631667314;
    if (i == 122) cout << 548656698;
    if (i == 123) cout << 730626984;
    if (i == 124) cout << 146295220;
    if (i == 125) cout << 674398632;
    if (i == 126) cout << 400383348;
    if (i == 127) cout << 454138904;
    if (i == 128) cout << 786220712;
    if (i == 129) cout << 118620797;
    if (i == 130) cout << 233440672;
    if (i == 131) cout << 217349271;
    if (i == 132) cout << 274853536;
    if (i == 133) cout << 310607544;
    if (i == 134) cout << 105221205;
    if (i == 135) cout << 769566615;
    if (i == 136) cout << 853585061;
    if (i == 137) cout << 800665807;
    if (i == 138) cout << 695377419;
    if (i == 139) cout << 924327065;
    if (i == 140) cout << 388199705;
    if (i == 141) cout << 551624811;
    if (i == 142) cout << 721435546;
    if (i == 143) cout << 501720515;
    if (i == 144) cout << 308465454;
    if (i == 145) cout << 825369234;
    if (i == 146) cout << 396065729;
    if (i == 147) cout << 451899519;
    if (i == 148) cout << 295058424;
    if (i == 149) cout << 142088952;
    if (i == 150) cout << 473485086;
    if (i == 151) cout << 378771634;
    if (i == 152) cout << 734511215;
    if (i == 153) cout << 462404399;
    if (i == 154) cout << 959198328;
    if (i == 155) cout << 337668263;
    if (i == 156) cout << 794122911;
    if (i == 157) cout << 38911400;
    if (i == 158) cout << 951992982;
    if (i == 159) cout << 472696081;
    if (i == 160) cout << 373904752;
    if (i == 161) cout << 105884826;
    if (i == 162) cout << 630251717;
    if (i == 163) cout << 28980684;
    if (i == 164) cout << 845136347;
    if (i == 165) cout << 353665773;
    if (i == 166) cout << 691661192;
    if (i == 167) cout << 19922354;
    if (i == 168) cout << 231463797;
    if (i == 169) cout << 757917231;
    if (i == 170) cout << 242739918;
    if (i == 171) cout << 979036950;
    if (i == 172) cout << 713722080;
    if (i == 173) cout << 234689388;
    if (i == 174) cout << 2243164;
    if (i == 175) cout << 209872853;
    if (i == 176) cout << 240808787;
    if (i == 177) cout << 539523346;
    if (i == 178) cout << 425797848;
    if (i == 179) cout << 913772061;
    if (i == 180) cout << 224613100;
    if (i == 181) cout << 421742777;
    if (i == 182) cout << 222232478;
    if (i == 183) cout << 92712941;
    if (i == 184) cout << 215137570;
    if (i == 185) cout << 949901408;
    if (i == 186) cout << 274827432;
    if (i == 187) cout << 15162482;
    if (i == 188) cout << 593145989;
    if (i == 189) cout << 274574232;
    if (i == 190) cout << 239282092;
    if (i == 191) cout << 762720192;
    if (i == 192) cout << 804146934;
    if (i == 193) cout << 500629424;
    if (i == 194) cout << 565985054;
    if (i == 195) cout << 81127381;
    if (i == 196) cout << 671811155;
    if (i == 197) cout << 655565571;
    if (i == 198) cout << 890331075;
    if (i == 199) cout << 237994348;
    if (i == 200) cout << 743647404;
    if (i == 201) cout << 667160634;
    if (i == 202) cout << 713914299;
    if (i == 203) cout << 668506729;
    if (i == 204) cout << 741341289;
    if (i == 205) cout << 277636808;
    if (i == 206) cout << 762781382;
    if (i == 207) cout << 14272789;
    if (i == 208) cout << 902864131;
    if (i == 209) cout << 567443405;
    if (i == 210) cout << 149113383;
    if (i == 211) cout << 648844381;
    if (i == 212) cout << 825489976;
    if (i == 213) cout << 933016723;
    if (i == 214) cout << 192288078;
    if (i == 215) cout << 734493315;
    if (i == 216) cout << 240985733;
    if (i == 217) cout << 861817693;
    if (i == 218) cout << 762711459;
    if (i == 219) cout << 525904609;
    if (i == 220) cout << 532463481;
    if (i == 221) cout << 377133989;
    if (i == 222) cout << 620711079;
    if (i == 223) cout << 772561562;
    if (i == 224) cout << 980733194;
    if (i == 225) cout << 227599811;
    if (i == 226) cout << 162774370;
    if (i == 227) cout << 209512798;
    if (i == 228) cout << 787116594;
    if (i == 229) cout << 3509258;
    if (i == 230) cout << 748795368;
    if (i == 231) cout << 378035466;
    if (i == 232) cout << 612938915;
    if (i == 233) cout << 802091952;
    if (i == 234) cout << 857679599;
    if (i == 235) cout << 481748937;
    if (i == 236) cout << 493370392;
    if (i == 237) cout << 358420805;
    if (i == 238) cout << 48301629;
    if (i == 239) cout << 412001241;
    if (i == 240) cout << 463126722;
    if (i == 241) cout << 509578422;
    if (i == 242) cout << 967799131;
    if (i == 243) cout << 994766554;
    if (i == 244) cout << 687287243;
    if (i == 245) cout << 863623583;
    if (i == 246) cout << 771554899;
    if (i == 247) cout << 690911527;
    if (i == 248) cout << 855314994;
    if (i == 249) cout << 923686429;
    if (i == 250) cout << 246862514;
    if (i == 251) cout << 192479791;
    if (i == 252) cout << 133487041;
    if (i == 253) cout << 703444043;
    if (i == 254) cout << 295281758;
    if (i == 255) cout << 801816257;
    if (i == 256) cout << 920762934;
    if (i == 257) cout << 749306433;
    if (i == 258) cout << 973004841;
    if (i == 259) cout << 848644684;
    if (i == 260) cout << 560026478;
    if (i == 261) cout << 952127278;
    if (i == 262) cout << 616654635;
    if (i == 263) cout << 839390326;
    if (i == 264) cout << 975154012;
    if (i == 265) cout << 409583672;
    if (i == 266) cout << 635350249;
    if (i == 267) cout << 343228425;
    if (i == 268) cout << 335331602;
    if (i == 269) cout << 223826406;
    if (i == 270) cout << 952341037;
    if (i == 271) cout << 589677800;
    if (i == 272) cout << 249747234;
    if (i == 273) cout << 555694261;
    if (i == 274) cout << 137143500;
    if (i == 275) cout << 628190328;
    if (i == 276) cout << 461598392;
    if (i == 277) cout << 431912756;
    if (i == 278) cout << 29349807;
    if (i == 279) cout << 759199489;
    if (i == 280) cout << 783281228;
    if (i == 281) cout << 781971312;
    if (i == 282) cout << 915823407;
    if (i == 283) cout << 388508707;
    if (i == 284) cout << 718062705;
    if (i == 285) cout << 27424111;
    if (i == 286) cout << 309999451;
    if (i == 287) cout << 963383322;
    if (i == 288) cout << 831185229;
    if (i == 289) cout << 132910888;
    if (i == 290) cout << 347028136;
    if (i == 291) cout << 850484840;
    if (i == 292) cout << 223055285;
    if (i == 293) cout << 142335980;
    if (i == 294) cout << 144754000;
    if (i == 295) cout << 772005560;
    if (i == 296) cout << 81796039;
    if (i == 297) cout << 167696020;
    if (i == 298) cout << 79454283;
    if (i == 299) cout << 172772542;
    if (i == 300) cout << 201056991;
    if (i == 301) cout << 484957644;
    if (i == 302) cout << 716630285;
    if (i == 303) cout << 763194701;
    if (i == 304) cout << 211505841;
    if (i == 305) cout << 903448791;
    if (i == 306) cout << 926964672;
    if (i == 307) cout << 257752668;
    if (i == 308) cout << 482951716;
    if (i == 309) cout << 411539070;
    if (i == 310) cout << 620249847;
    if (i == 311) cout << 592476107;
    if (i == 312) cout << 170473128;
    if (i == 313) cout << 814662613;
    if (i == 314) cout << 898000271;
    if (i == 315) cout << 57354872;
    if (i == 316) cout << 361106091;
    if (i == 317) cout << 488697643;
    if (i == 318) cout << 889007954;
    if (i == 319) cout << 138725767;
    if (i == 320) cout << 684860983;
    if (i == 321) cout << 36248116;
    if (i == 322) cout << 304610143;
    if (i == 323) cout << 137633385;
    if (i == 324) cout << 413715776;
    if (i == 325) cout << 99010024;
    if (i == 326) cout << 779653665;
    if (i == 327) cout << 100387568;
    if (i == 328) cout << 286328069;
    if (i == 329) cout << 564731826;
    if (i == 330) cout << 621740468;
    if (i == 331) cout << 943513219;
    if (i == 332) cout << 506666491;
    if (i == 333) cout << 249987886;
    if (i == 334) cout << 553719884;
    if (i == 335) cout << 769853086;
    if (i == 336) cout << 337485319;
    if (i == 337) cout << 702455584;
    if (i == 338) cout << 809637762;
    if (i == 339) cout << 755400257;
    if (i == 340) cout << 892290368;
    if (i == 341) cout << 502180086;
    if (i == 342) cout << 364275817;
    if (i == 343) cout << 118162370;
    if (i == 344) cout << 873374339;
    if (i == 345) cout << 261271695;
    if (i == 346) cout << 970132574;
    if (i == 347) cout << 744105500;
    if (i == 348) cout << 434447173;
    if (i == 349) cout << 117975095;
    if (i == 350) cout << 383088393;
    if (i == 351) cout << 625447969;
    if (i == 352) cout << 180281249;
    if (i == 353) cout << 545367713;
    if (i == 354) cout << 133236931;
    if (i == 355) cout << 360175662;
    if (i == 356) cout << 148087453;
    if (i == 357) cout << 806871297;
    if (i == 358) cout << 498529036;
    if (i == 359) cout << 886076476;
    if (i == 360) cout << 65645000;
    if (i == 361) cout << 465138299;
    if (i == 362) cout << 967109895;
    if (i == 363) cout << 331362616;
    if (i == 364) cout << 472283705;
    if (i == 365) cout << 796894900;
    if (i == 366) cout << 199697765;
    if (i == 367) cout << 503759892;
    if (i == 368) cout << 472807906;
    if (i == 369) cout << 187586706;
    if (i == 370) cout << 941198065;
    if (i == 371) cout << 782234442;
    if (i == 372) cout << 57693411;
    if (i == 373) cout << 18678611;
    if (i == 374) cout << 82626204;
    if (i == 375) cout << 395317191;
    if (i == 376) cout << 570588915;
    if (i == 377) cout << 152519440;
    if (i == 378) cout << 449852456;
    if (i == 379) cout << 63696518;
    if (i == 380) cout << 763741345;
    if (i == 381) cout << 878748386;
    if (i == 382) cout << 494317541;
    if (i == 383) cout << 444782633;
    if (i == 384) cout << 93316211;
    if (i == 385) cout << 929164666;
    if (i == 386) cout << 529288371;
    if (i == 387) cout << 165769871;
    if (i == 388) cout << 730546850;
    if (i == 389) cout << 955877127;
    if (i == 390) cout << 994202767;
    if (i == 391) cout << 492009567;
    if (i == 392) cout << 275683011;
    if (i == 393) cout << 415902127;
    if (i == 394) cout << 95725776;
    if (i == 395) cout << 718047399;
    if (i == 396) cout << 786963365;
    if (i == 397) cout << 73091278;
    if (i == 398) cout << 986172399;
    if (i == 399) cout << 174591541;
    if (i == 400) cout << 913259286;
}

/*
#include <bits/stdc++.h>
 
using namespace std;
//using namespace __gnu_pbds;
  
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
  
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);
 
int done[401][401];
ll dp[401][401], fac[401]; // Singer i-house with ordered selection of j distinct paths
 
ll inv(ll b) {
    ll ans = 1, po = MOD-2;
    while (po) {
        if (po & 1) ans = (ans*b) % MOD;
        b = (b*b) % MOD;
        po /= 2;
    }
    return ans;
}
 
ll combo(int a, int b) {
    ll temp = fac[a]*inv(fac[b]) % MOD;
    temp = (temp*inv(fac[a-b])) % MOD;
    return temp;
}
 
ll get(int a, int b) {
    if (done[a][b]) return dp[a][b];
    if (a == 0) {
        done[a][b] = 1;
        if (b == 0) return dp[a][b] = 1;
        return dp[a][b] = 0;
    }
    
    F0R(i,b+1) {
        ll temp = get(a-1,i)*get(a-1,b-i) % MOD;
        dp[a][b] = (dp[a][b]+combo(b,i)*temp) % MOD;
    }
     
    F0R(i,b) {
        ll temp = get(a-1,i)*get(a-1,b-1-i) % MOD;
        temp = temp*combo(b-1,i) % MOD;
        dp[a][b] = (dp[a][b]+b*temp) % MOD;
    }
     
    FOR(i,1,b+1) {
        ll temp = get(a-1,i)*get(a-1,b-i) % MOD;
        temp = temp*combo(b-1,b-i) % MOD;
        temp = temp*b % MOD;
        dp[a][b] = (dp[a][b]+4*temp) % MOD;
    }
     
    FOR(i,2,b+2) {
        ll temp = get(a-1,i)*get(a-1,b+1-i) % MOD;
        temp = temp*b % MOD;
        temp = temp*combo(b-1,i-2) % MOD; 
        dp[a][b] = (dp[a][b]+2*temp) % MOD;
    }
     
    FOR(i,1,b+1) {
        ll temp = get(a-1,i)*get(a-1,b+1-i) % MOD;
        temp = temp*b % MOD;
        temp = temp*combo(b-1,i-1) % MOD; 
        dp[a][b] = (dp[a][b]+2*temp) % MOD;
    }
     
    done[a][b] = 1;
    return dp[a][b];
}
 
int main() {
    fac[0] = 1;
    FOR(i,1,401) fac[i] = (i*fac[i-1]) % MOD;
    get(400,1);
    FOR(i,1,401) cout << "if (i == " << i << ") cout << " << dp[i][1] << "\n";
}*/