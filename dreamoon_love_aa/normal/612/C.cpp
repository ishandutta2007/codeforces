#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1 << 20;
void err(){
	puts("Impossible");
	exit(0);
}
char s[SIZE];
char stk[SIZE];
int sn;
map<char,char> H{{'>','<'},{'}','{'},{')','('},{']','['},};
int main(){
    cin>>s;
	int an = 0;
        for(int i = 0; s[i]; i++) {
        if(H.count(s[i])){
            if(!sn || H.count(stk[sn-1])) {
                err();
            }
            sn--;
            an += (stk[sn] != H[s[i]]);
        }
        else{
            stk[sn++] = s[i];
        }
    }
    if(sn) { err(); }
    printf("%d\n",an);
    return 0;
}