#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

int x;
char s[20];

int main(){
    scanf("%d", &x);
    scanf("%s", s + 1);
    scanf("%s", s + 1);
    int l = strlen(s + 1);
    if (s[l] == 'k'){
        if (x == 5 || x == 6) printf("53\n");
        else printf("52\n");
    }else{
        if (x <= 29) printf("12\n");
        else if (x <= 30) printf("11\n");
        else printf("7\n");
    }
  return 0;
}