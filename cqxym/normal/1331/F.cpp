#include <bits/stdc++.h>
using namespace std;
 
string e[200] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og", "Uue"};
 
bool f(string s, int st, int ed) {
    if (st == ed) return true;
    for (int i = 0; i < 118; i++) {
        if (st + e[i].size() <= ed) {
            bool match = true;
            for (int j = 0; j < e[i].size(); j++) {
                int c = (j == 0 ? e[i][j] - 'A' : e[i][j] - 'a');
                if (s[st + j] - 'A' != c) {
                    match = false;
                    break;
                }
            }
            if (match && f(s, st + e[i].size(), ed)) {
                return true;
            }
        }
    }
    return false;
}
 
int main() {
 
    string s;
    cin >> s;
    int n = s.size();
    if (f(s, 0, n)) {
        puts("YES");
    } else {
        puts("NO");
    }
 
    return 0;
}