#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!
string table[119] = {
"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar",
"K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", 
"Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Te", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", 
"I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", 
"Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", 
"Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm","Md", "No", "Lr",
"Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og", "Uue"};


string p,a;
bool ok[100];

int main(){
    for(int i=0;i<=118;i++){
        for(int j=0;j<table[i].size();j++){
            table[i][j]&=0xdf;
        }
    }
    cin>>a;
    p=" ";p+=a;
    ok[0]=1;
    for(int i=1;i<=a.size();i++){
        for(int j=0;j<=118;j++){
            int lp=i-table[j].size();
            if(lp>=0&&ok[lp]&&table[j]==p.substr(lp+1,table[j].size()))ok[i]=1;
        }
    }
    cout<<(ok[a.size()]?"YES":"NO");
    return 0;
}