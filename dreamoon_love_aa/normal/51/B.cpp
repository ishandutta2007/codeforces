#include<stdio.h>
#include<algorithm>
using namespace std;
char get(){
    char c;
    while((c=getchar())&&c=='\n');
    return c;
}
int an[100000],ann,d[100000];
main(){
    int m=-1,i;
    char c;
    while(get()!=EOF){
        c=get();
        if(c!='/'){
            c=get();
            if(c=='a'){
                for(i=0;i<4;i++)
                    get();
                m++;
                d[m]=0;
            }
            else if(c=='d'){
                get();
                d[m]++;
            }
            else get();
        }
        else{
            get();
            c=get();
            if(c=='a'){
                an[ann++]=d[m];
                m--;
                for(i=0;i<4;i++)get();
            }
            else get();
        }
    }
    sort(an,an+ann);
    for(i=0;i<ann;i++){
        if(i)putchar(' ');
        printf("%d",an[i]);
    }
    puts("");
}