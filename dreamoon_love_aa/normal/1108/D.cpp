#include<bits/stdc++.h>
using namespace std;
char c[5]="BGR";
char s[200005];
int n;
int an;
void ch(int id){
    an++;
    for(int i=0;i<3;i++){
        if(id&&c[i]==s[id-1])continue;
        if(c[i]==s[id+1])continue;
        s[id]=c[i];
        return;
    }
}
int main(){
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0,j;i<n;i=j){
        for(j=i+1;j<n&&s[i]==s[j];j++);
        if((j-i)%2==0){
            for(int k=i;k<j;k+=2)ch(k);
        }
        else{
            for(int k=i+1;k<j;k+=2)ch(k);
        }
    }
    printf("%d\n",an);
    puts(s);
    return 0;
}