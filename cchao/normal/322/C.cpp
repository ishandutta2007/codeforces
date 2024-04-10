#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    long long a, b;
    char s[110];
    cin >> a >> b >> s;

    long long vx = 0, vy = 0;
    for(int i = 0; s[i]; ++i) {
        if(s[i] == 'L') vx--;
        else if(s[i] == 'R') vx++;
        else if(s[i] == 'D') vy--;
        else if(s[i] == 'U') vy++;
    }
    long long x = 0, y = 0;
    int len = strlen(s);
    for(int i = 0; i <= len; ++i) {
        int aa = 0, bb = 0;
        if(vx==0 && a==x) aa = 1;
        if(vy==0 && b==y) bb = 1;


        if(vx == 0 && a != x) {}
        else if(vy == 0 && b != y) {}
        else if((a-x)*vx < 0 || (b-y)*vy < 0 ) {}
        else if((aa||(a-x)%vx==0) &&
            (bb||(b-y)%vy==0) &&
            ((aa||bb)||(a-x)/vx == (b-y)/vy))
        {
            puts("Yes");
            return 0;
        }

        if(s[i] == 'L') x--;
        else if(s[i] == 'R') x++;
        else if(s[i] == 'D') y--;
        else if(s[i] == 'U') y++;

    }
    puts("No");
    return 0;
}