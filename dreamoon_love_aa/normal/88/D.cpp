#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
using namespace std;
map<string,int>Map;
void error(){puts("errtype");}
main(){
    int n,i,len,k;
    char def[16],s1[64],s2[64];
    scanf("%d",&n);
    Map["void"]=0;
    for(k=0;k<n;k++){
        scanf("%s",def);
        if(def[4]=='d'){
            int tmp=0;
            scanf("%s%s",s1,s2);
            len=strlen(s1);
            for(i=0;i<len&&s1[len-1-i]=='*';i++);
            s1[len-i]=0;
            tmp=i;
            for(i=0;s1[i]=='&';i++);
            tmp-=i;
            if(!Map.count(s1+i)||Map[s1+i]<0){
                Map[s2]=-1;
            }
            else{
                tmp+=Map[s1+i];
                if(tmp<0)tmp=-1;
                Map[s2]=tmp;
            }
        }
        else{
            scanf("%s",s1);
            int tmp;
            len=strlen(s1);
            for(i=0;i<len&&s1[len-1-i]=='*';i++);
            s1[len-i]=0;
            tmp=i;
            for(i=0;s1[i]=='&';i++);
            tmp-=i;            
            if(!Map.count(s1+i)){
                error();
            }
            else{
                if(Map[s1+i]<0)error();
                else{
                    tmp+=Map[s1+i];
                    if(tmp<0)error();
                    else{
                        printf("void");
                        while(tmp){
                            printf("*");
                            tmp--;
                        }
                        puts("");
                    }
                }
            }
        }
    }
}