#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <utility>

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair

using namespace std;

bool u[30000];
vector <int> Pr;
int A[310];
//set <int> Res;

bool isprime (int a)
{
  for (int i=0; Pr[i]*Pr[i]<=a; i++)
    if ((a%Pr[i])==0)
      return 0;
  return 1;
}

int solve2 (int r)
{
  int res=0;
  if (r==0)
    return 0;
  if (r>=2)
    res++;
  int l=1;
  while (l+1000000<=r)
    res+=A[l/1000000], l+=1000000;
  int i, j;
  for (i=2; i*i<r; i+=2)
    for (j=0; i*i+(2*j+1)*(2*j+1)<=r; j++)
      if (i*i+(2*j+1)*(2*j+1)>=l && isprime(i*i+(2*j+1)*(2*j+1)))
        res++;
  return res;
}

/*void solve (int l, int r)
{
  int i, j, cnt=0;
  for (i=2; i*i<r; i+=2)
    for (j=0; i*i+(2*j+1)*(2*j+1)<=r; j++)
      if (i*i+(2*j+1)*(2*j+1)>=l && isprime(i*i+(2*j+1)*(2*j+1)))
      {
        cnt++;
        //Res.insert(i*i+(2*j+1)*(2*j+1));
      }
  cerr<<cnt<<endl;
  //printf("A[%d]=%d;\n", l/(1000000), cnt);
}    */

int main()
{
  int i, l, r, j;
  //freopen(".in", "r", stdin);
 // freopen(".out", "w", stdout);

  A[0]=39175;
A[1]=35241;
A[2]=33867;
A[3]=33219;
A[4]=32691;
A[5]=32139;
A[6]=31928;
A[7]=31499;
A[8]=31341;
A[9]=31080;
A[10]=30899;
A[11]=30913;
A[12]=30576;
A[13]=30405;
A[14]=30301;
A[15]=30139;
A[16]=30087;
A[17]=30002;
A[18]=29854;
A[19]=29814;
A[20]=29600;
A[21]=29719;
A[22]=29406;
A[23]=29422;
A[24]=29436;
A[25]=29274;
A[26]=29336;
A[27]=29150;
A[28]=29172;
A[29]=29094;
A[30]=29091;
A[31]=28875;
A[32]=28873;
A[33]=28902;
A[34]=28653;
A[35]=28729;
A[36]=28749;
A[37]=28687;
A[38]=28754;
A[39]=28595;
A[40]=28584;
A[41]=28417;
A[42]=28392;
A[43]=28489;
A[44]=28355;
A[45]=28315;
A[46]=28386;
A[47]=28313;
A[48]=28256;
A[49]=28258;
A[50]=28169;
A[51]=28080;
A[52]=28070;
A[53]=28052;
A[54]=28033;
A[55]=28035;
A[56]=27971;
A[57]=28017;
A[58]=27892;
A[59]=27899;
A[60]=27976;
A[61]=27713;
A[62]=27847;
A[63]=27868;
A[64]=27831;
A[65]=27821;
A[66]=27783;
A[67]=27794;
A[68]=27716;
A[69]=27699;
A[70]=27611;
A[71]=27660;
A[72]=27723;
A[73]=27534;
A[74]=27588;
A[75]=27680;
A[76]=27510;
A[77]=27458;
A[78]=27448;
A[79]=27443;
A[80]=27498;
A[81]=27578;
A[82]=27454;
A[83]=27448;
A[84]=27327;
A[85]=27347;
A[86]=27304;
A[87]=27472;
A[88]=27326;
A[89]=27266;
A[90]=27219;
A[91]=27227;
A[92]=27345;
A[93]=27189;
A[94]=27308;
A[95]=27228;
A[96]=27199;
A[97]=27167;
A[98]=27086;
A[99]=27143;
A[100]=27101;
A[101]=27097;
A[102]=27178;
A[103]=27021;
A[104]=27107;
A[105]=27013;
A[106]=26975;
A[107]=27086;
A[108]=27143;
A[109]=27133;
A[110]=26917;
A[111]=27074;
A[112]=26976;
A[113]=26792;
A[114]=26905;
A[115]=26928;
A[116]=26827;
A[117]=26892;
A[118]=26881;
A[119]=26925;
A[120]=26796;
A[121]=26823;
A[122]=26879;
A[123]=26934;
A[124]=26831;
A[125]=26788;
A[126]=26788;
A[127]=26857;
A[128]=26912;
A[129]=26781;
A[130]=26706;
A[131]=26816;
A[132]=26714;
A[133]=26709;
A[134]=26784;
A[135]=26590;
A[136]=26671;
A[137]=26605;
A[138]=26625;
A[139]=26836;
A[140]=26539;
A[141]=26668;
A[142]=26606;
A[143]=26717;
A[144]=26639;
A[145]=26632;
A[146]=26642;
A[147]=26559;
A[148]=26499;
A[149]=26563;
A[150]=26417;
A[151]=26555;
A[152]=26338;
A[153]=26617;
A[154]=26477;
A[155]=26456;
A[156]=26642;
A[157]=26415;
A[158]=26339;
A[159]=26483;
A[160]=26470;
A[161]=26399;
A[162]=26468;
A[163]=26593;
A[164]=26352;
A[165]=26354;
A[166]=26345;
A[167]=26398;
A[168]=26378;
A[169]=26469;
A[170]=26346;
A[171]=26372;
A[172]=26390;
A[173]=26434;
A[174]=26306;
A[175]=26359;
A[176]=26331;
A[177]=26390;
A[178]=26348;
A[179]=26469;
A[180]=26168;
A[181]=26342;
A[182]=26128;
A[183]=26258;
A[184]=26390;
A[185]=26251;
A[186]=26268;
A[187]=26241;
A[188]=26223;
A[189]=26395;
A[190]=25941;
A[191]=26110;
A[192]=26293;
A[193]=26226;
A[194]=26247;
A[195]=26183;
A[196]=26099;
A[197]=26034;
A[198]=26139;
A[199]=26190;
A[200]=26168;
A[201]=26268;
A[202]=26107;
A[203]=26223;
A[204]=26137;
A[205]=26001;
A[206]=26145;
A[207]=26052;
A[208]=25999;
A[209]=26168;
A[210]=26038;
A[211]=26225;
A[212]=26168;
A[213]=26057;
A[214]=26095;
A[215]=26173;
A[216]=26094;
A[217]=25948;
A[218]=25966;
A[219]=25999;
A[220]=25994;
A[221]=26045;
A[222]=26114;
A[223]=25971;
A[224]=26158;
A[225]=25913;
A[226]=26090;
A[227]=25813;
A[228]=25930;
A[229]=25903;
A[230]=25956;
A[231]=26020;
A[232]=26001;
A[233]=25825;
A[234]=25939;
A[235]=25950;
A[236]=26045;
A[237]=25925;
A[238]=26008;
A[239]=25808;
A[240]=26013;
A[241]=25938;
A[242]=25712;
A[243]=25883;
A[244]=25989;
A[245]=25900;
A[246]=25794;
A[247]=25760;
A[248]=25943;
A[249]=25783;
A[250]=25953;
A[251]=25667;
A[252]=25756;
A[253]=25915;
A[254]=25963;
A[255]=25824;
A[256]=25858;
A[257]=25833;
A[258]=25905;
A[259]=25729;
A[260]=25951;
A[261]=25770;
A[262]=25971;
A[263]=25767;
A[264]=25859;
A[265]=25928;
A[266]=25627;
A[267]=25767;
A[268]=25863;
A[269]=25623;
A[270]=25772;
A[271]=25706;
A[272]=25657;
A[273]=25806;
A[274]=25819;
A[275]=25724;
A[276]=25712;
A[277]=25735;
A[278]=25587;
A[279]=25726;
A[280]=25606;
A[281]=25780;
A[282]=25597;
A[283]=25743;
A[284]=25704;
A[285]=25615;
A[286]=25592;
A[287]=25770;
A[288]=25735;
A[289]=25588;
A[290]=25755;
A[291]=25680;
A[292]=25519;
A[293]=25692;
A[294]=25737;
A[295]=25552;
A[296]=25616;
A[297]=25639;
A[298]=25521;


  for (i=2; i<30000; i++)
    if (!u[i])
    {
      Pr.pb(i);
      for (j=i*i; j<30000; j+=i)
        u[j]=1;
    }
  scanf("%d%d", &l, &r);
  //solve(l,r);
  printf("%d\n", solve2(r)-solve2(l-1));
  /*for (i=0; i<299; i++)
  {
    cerr<<i<<endl;
    solve(i*1000000+1,(i+1)*1000000); 
  }    */
  return 0;
}