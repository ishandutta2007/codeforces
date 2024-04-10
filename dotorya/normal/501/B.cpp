#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
using namespace std;
typedef map <string, string> mss;

mss M;
char t1[105], t2[105];
int main() {
    int N, i;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%s %s", t1, t2);
        string s1 = string(t1);
        string s2 = string(t2);
        mss::iterator it;
        if(M.empty()) {
            M[s1] = s2;
            continue;
        }
        int check = 0;
        for(mss::iterator it = M.begin(); it != M.end(); it++) {
            if(it->second == s1) {
                M[it->first] = s2;
                check = 1;
                break;
            }
        }
        if(check == 0) M[s1] = s2;
    }
    
    printf("%d\n", M.size());
    for(mss::iterator it = M.begin(); it != M.end(); it++) {
        string x = it->first;
        cout << x << " " << it->second << endl;
    }
    return 0;
}