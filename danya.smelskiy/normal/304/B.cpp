#include <bits/stdc++.h>
using namespace std;
string s,ss;
int q[15];
int ans;
int year1,month1,day1;
int year2,month2,day2;

int main(){
    q[1]=31; q[2]=29; q[3]=31; q[4]=30; q[5]=31; q[6]=30; q[7]=31; q[8]=31; q[9]=30; q[10]=31; q[11]=30; q[12]=31;
    cin>>s>>ss;
    year1=(s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+(s[3]-'0');
    month1=(s[5]-'0')*10+(s[6]-'0');
    day1=(s[8]-'0')*10+(s[9]-'0');
    s=ss;
    year2=(s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+(s[3]-'0');
    month2=(s[5]-'0')*10+(s[6]-'0');
    day2=(s[8]-'0')*10+(s[9]-'0');
    if (year1>year2 || (year1==year2 && month1>month2) || (year1==year2 && month1==month2 && day1>day2)) {
        swap(year1,year2);
        swap(month1,month2);
        swap(day1,day2);
    }
    for (int i=year1+1;i<year2;++i){
        if(i%4==0 && (i%100!=0 || i%400==0)) ans+=366;
        else ans+=365;
    }
    if (year1%4!=0 || (year1%100==0 && year1%400!=0)) q[2]=28;
    if (year1==year2) {
        while (!(month1==month2 && day1==day2)) {
            ++ans;
            if (day1==q[month1]) {
                day1=1;
                month1++;
            } else ++day1;
        }
        cout<<ans;
        return 0;
    }
    ++ans;
    while (!(day1==31 && month1==12)){
        ++ans;
        if (day1==q[month1]) {
            day1=1;
            month1++;
        } else day1++;
    }
    q[2]=29;
    if (year2%4!=0 || (year2%100==0 && year2%400!=0)) q[2]=28;
    day1=1;
    month1=1;
    while (!(day1==day2 && month1==month2)){
        ++ans;
        if (day1==q[month1]) {
            day1=1;
            month1++;
        } else day1++;
    }
    cout<<ans;
}