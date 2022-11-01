#include<bits/stdc++.h>
using namespace std;


const string ele[]={
"H",
"He",
"Li",
"Be",
"B",
"C",
"N",
"O",
"F",
"Ne",
"Na",
"Mg",
"Al",
"Si",
"P",
"S",
"Cl",
"Ar",
"K",
"Ca",
"Sc",
"Ti",
"V",
"Cr",
"Mn",
"Fe",
"Co",
"Ni",
"Cu",
"Zn",
"Ga",
"Ge",
"As",
"Se",
"Br",
"Kr",
"Rb",
"Sr",
"Y",
"Zr",
"Nb",
"Mo",
"Tc",
"Ru",
"Rh",
"Pd",
"Ag",
"Cd",
"In",
"Sn",
"Sb",
"Te",
"I",
"Xe",
"Cs",
"Ba",
"Hf",
"Ta",
"W",
"Re",
"Os",
"Ir",
"Pt",
"Au",
"Hg",
"Tl",
"Pb",
"Bi",
"Po",
"At",
"Rn",
"Fr",
"Ra",
"Rf",
"Db",
"Sg",
"Bh",
"Hs",
"Mt",
"Ds",
"Rg",
"Cn",
"Nh",
"Fl",
"Mc",
"Lv",
"Ts",
"Og",
"La",
"Ce",
"Pr",
"Nd",
"Pm",
"Sm",
"Eu",
"Gd",
"Tb",
"Dy",
"Ho",
"Er",
"Tm",
"Yb",
"Lu",
"Ac",
"Th",
"Pa",
"U",
"Np",
"Pu",
"Am",
"Cm",
"Bk",
"Cf",
"Es",
"Fm",
"Md",
"No",
"Lr"};

char s[15];
int n;
bool dp[15];

bool match1(char *t){
    for(int i=0;i<118;i++)if(ele[i].size()==1&&ele[i][0]==t[0])return true;
    return false;
}

bool match2(char *t){
    for(int i=0;i<118;i++)if(ele[i].size()==2&&ele[i][0]==t[0]&&ele[i][1]-('a'-'A')==t[1])return true;
    return false;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s+1;
    n=strlen(s+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(match1(s+i))dp[i]|=dp[i-1];
        if(i>1&&match2(s+i-1))dp[i]|=dp[i-2];
    }
    cout<<(dp[n]?"YES":"NO")<<endl;

    return 0;
}