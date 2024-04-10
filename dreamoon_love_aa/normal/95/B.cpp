#include<stdio.h>
#include<string.h>
char s[100024],an[100024];
int len;
bool f(){
    int k1,k2;
    k1=k2=len/2;
    int i,j;
    for(i=0;i<len;i++){
        if(s[i]!='4'&&s[i]!='7')break;
        if(s[i]=='4'){
            k1--;
            if(k1<0){
                for(j=0;j<i;j++)printf("%c",s[j]);
                for(;j<len;j++)printf("7");
                puts("");
                return 1;
            }
        }
        else if(s[i]=='7'){
            k2--;
            if(k2<0){
                for(j=i-1;j>=0&&s[j]=='4';j--);
                while(j>=0&&s[j]=='7')j--;
                if(j<0)return 0;
                k1=k2=len/2;
                for(i=0;i<j;i++){
                    putchar(s[i]);
                    if(s[i]=='4')k1--;
                    else k2--;
                }
                k2--;
                putchar('7');
                while(k1>0){
                    putchar('4');
                    k1--;
                }
                while(k2>0){
                    putchar('7');
                    k2--;
                }
                puts("");
                return 1;
            }
        }
    }
    if(i==len){
        puts(s);
        return 1;
    }
    if(s[i]<'4'){
        for(j=0;j<i;j++)printf("%c",s[j]);
        if(k1>0){
            putchar('4');
            k1--;
        }
        else{
            putchar('7');
            k2--;
        }
        while(k1>0){
            putchar('4');
            k1--;
        }
        while(k2>0){
            putchar('7');
            k2--;
        }
        puts("");
        return 1;
    }
    if(s[i]<'7'){
        if(k2>0){
            for(j=0;j<i;j++)printf("%c",s[j]);
            putchar('7');
            k2--;
            while(k1>0){
                putchar('4');
                k1--;
            }
            while(k2>0){
                putchar('7');
                k2--;
            }
            puts("");
            return 1;
        }
        else{
            for(j=i-1;j>=0&&s[j]=='4';j--);
            while(j>=0&&s[j]=='7')j--;
            if(j<0)return 0;
            k1=k2=len/2;
            for(i=0;i<j;i++){
                putchar(s[i]);
                if(s[i]=='4')k1--;
                else if(s[i]=='7')k2--;
            }
            printf("7");
            k2--;
            while(k1>0){
                putchar('4');
                k1--;
            }
            while(k2>0){
                putchar('7');
                k2--;
            }
            puts("");
            return 1;
        }
    }
    else{
        if(i==0)return 0;
        if(k2==0){
            for(j=i-1;j>=0&&s[j]=='4';j--);
            while(j>=0&&s[j]=='7')j--;
            if(j<0)return 0;
            k1=k2=len/2;
            for(i=0;i<j;i++){
                printf("%c",s[i]);
                if(s[i]=='4')k1--;
                else if(s[i]=='7')k2--;
            }
            putchar('7');
            k2--;
            while(k1>0){
                putchar('4');
                k1--;
            }
            while(k2>0){
                putchar('7');
                k2--;
            }
            puts("");
            return 1;
        }
        for(j=i-1;j>=0&&s[j]=='7';j--);
        if(j<0)return 0;
        else{
            k1=k2=len/2;
            for(i=0;i<j;i++){
                printf("%c",s[i]);
                if(s[i]=='4')k1--;
                else if(s[i]=='7')k2--;
            }
            putchar('7');
            k2--;
            while(k1>0){
                putchar('4');
                k1--;
            }
            while(k2>0){
                putchar('7');
                k2--;
            }
            puts("");
            return 1;
        }
    }
}
main(){
    int i;
    scanf("%s",s);
    len=strlen(s);
    if(len%2){
        int k=len/2+1;
        for(i=0;i<k;i++)putchar('4');
        for(i=0;i<k;i++)putchar('7');
        puts("");
    }
    else{
        if(!f()){
            int k=len/2+1;
            for(i=0;i<k;i++)putchar('4');
            for(i=0;i<k;i++)putchar('7');
            puts("");
        }
    }
}