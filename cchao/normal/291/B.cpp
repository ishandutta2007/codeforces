#include <cstdio>
char s[100010];
int sz = 0;
void print(){
    putchar('<');
    for(int i = 0; i < sz; ++i)
        putchar(s[i]);
    puts(">");
}
int main(){
    int c, f = 0;
    while((c=getchar())!=EOF){
        if(c=='\n') break;
        if(c=='"'){
            if(f==1) f=0;
            else f=1;
            if(sz || f==0){ print(); sz = 0;}
        }
        else if(f) s[sz++] = c;
        else{
            if(c==' '){
                if(sz){print(); sz =0;}
            }
            else s[sz++] = c;
        }
    }
    if(sz){print();}
}