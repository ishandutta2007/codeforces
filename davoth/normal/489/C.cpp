#include <bits/stdc++.h>
using namespace std;

int main() {
    int m,s;
    cin >> m >> s;
    int mm=m,sm=s;
    string ma, mi;
    if(s>9*m || s==0 && m>1){
        cout << -1 << ' ' << -1;
        return 0;
    }else if(s==0 && m==1){
        cout << 0 << ' ' << 0;
        return 0;
    }
    if((m-1)*9<s){
        mi+=to_string(s-(m-1)*9);
        s=(m-1)*9;
        m--;
    }else{
        mi+="1";
        s--;
        m--;
    }
    while(m--){
        if(s>=9){
            mi+="9";
            s-=9;
        }else if(s>0 && s<9) {
            mi.insert(mi.begin() + 1, (char)s+'0');
            s = 0;
        }else{
            mi.insert(mi.begin() + 1, '0');
        }
    }
    while(mm--){
        if(sm>=9){
            ma+='9';
            sm-=9;
        }else{
            ma+=(char)sm+'0';
            sm=0;
        }
    }
    cout << mi << ' ' << ma;
    return 0;
}