/*{{{*/
#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
string s=R"shik(
H - Hydrogen
He - Helium
Li - Lithium
Be - Beryllium
B - Boron
C - Carbon
N - Nitrogen
O - Oxygen
F - Fluorine
Ne - Neon
Na - Sodium
Mg - Magnesium
Al - Aluminum, Aluminium
Si - Silicon
P - Phosphorus
S - Sulfur
Cl - Chlorine
Ar - Argon
K - Potassium
Ca - Calcium
Sc - Scandium
Ti - Titanium
V - Vanadium
Cr - Chromium
Mn - Manganese
Fe - Iron
Co - Cobalt
Ni - Nickel
Cu - Copper
Zn - Zinc
Ga - Gallium
Ge - Germanium
As - Arsenic
Se - Selenium
Br - Bromine
Kr - Krypton
Rb - Rubidium
Sr - Strontium
Y - Yttrium
Zr - Zirconium
Nb - Niobium
Mo - Molybdenum
Tc - Technetium
Ru - Ruthenium
Rh - Rhodium
Pd - Palladium
Ag - Silver
Cd - Cadmium
In - Indium
Sn - Tin
Sb - Antimony
Te - Tellurium
I - Iodine
Xe - Xenon
Cs - Cesium
Ba - Barium
La - Lanthanum
Ce - Cerium
Pr - Praseodymium
Nd - Neodymium
Pm - Promethium
Sm - Samarium
Eu - Europium
Gd - Gadolinium
Tb - Terbium
Dy - Dysprosium
Ho - Holmium
Er - Erbium
Tm - Thulium
Yb - Ytterbium
Lu - Lutetium
Hf - Hafnium
Ta - Tantalum
W - Tungsten
Re - Rhenium
Os - Osmium
Ir - Iridium
Pt - Platinum
Au - Gold
Hg - Mercury
Tl - Thallium
Pb - Lead
Bi - Bismuth
Po - Polonium
At - Astatine
Rn - Radon
Fr - Francium
Ra - Radium
Ac - Actinium
Th - Thorium
Pa - Protactinium
U - Uranium
Np - Neptunium
Pu - Plutonium
Am - Americium
Cm - Curium
Bk - Berkelium
Cf - Californium
Es - Einsteinium
Fm - Fermium
Md - Mendelevium
No - Nobelium
Lr - Lawrencium
Rf - Rutherfordium
Db - Dubnium
Sg - Seaborgium
Bh - Bohrium
Hs - Hassium
Mt - Meitnerium
Ds - Darmstadtium
Rg - Roentgenium
Cn - Copernicium
Nh - Nihonium
Fl - Flerovium
Mc - Moscovium
Lv - Livermorium
Ts - Tennessine
Og - Oganesson
)shik";
int main(){
    vector<string>AA;
    REP(i,SZ(s)){
        if(s[i]=='-'){
            for(int j=i-1;j>=0;j--){
                if(s[j]>='A'&&s[j]<='Z'){
                    string tmp;
                    tmp+=s[j];
                    if(s[j+1]!=' '){
                        tmp+=s[j+1]-'a'+'A';
                    }
                    AA.PB(tmp);
                    break;
                }
            }
        }
    }
    char ker[24];
    RS(ker);
    int n=LEN(ker);
    int dp[24]={};
    dp[0]=1;
    REP(i,n){
        if(dp[i]){
            for(auto x:AA){
                if(SZ(x)==1){
                    if(ker[i]==x[0])dp[i+1]=1;
                }
                else{
                    if(ker[i]==x[0]&&ker[i+1]==x[1]){
                        dp[i+2]=1;
                    }
                }
            }
        }
    }
    W(dp[n]?"YES":"NO");
    return 0;
}