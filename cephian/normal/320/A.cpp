#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    char num[20];
    scanf("%s", &num);
    int i = 0;
    //0 = none
    //1 = 1
    //2 = 14
    //3 = 144
    int state = 0;

    while (num[i] != 0) {
        if (num[i] == '1') {
            if (state == 0 || state == 1 || state == 2 || state == 3) {
                state = 1;
            } else
                goto fail;
        } else if (num[i] == '4') {
            if (state == 1 || state == 2)
                ++state;
            else
                goto fail;
        } else {
            goto fail;
        }
        ++i;
    }
    printf("YES\n");
    return 0;

    fail: printf("NO\n");
    return 0;
}