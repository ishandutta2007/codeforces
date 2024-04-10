var n=parseInt(readline());
var arr=[];
for (var i=0;i<2880;++i) arr[i]=0;
for (var i=0;i<n;++i) {
    var arr1=readline().split(":");
    var h=parseInt(arr1[0]);
    var m=parseInt(arr1[1])+h*60;
    arr[m]=1;
    arr[m+1440]=1;
}
var pros=0;
var masleep=0;
for (var i=0;i<2880;++i) if (arr[i]===1) {
    if (i-pros-1>masleep) masleep=i-pros-1;
    pros=i;
}
var str='';
if ((masleep-masleep%60)/60<10) str='0';
var str1='';
if (masleep%60<10) str1='0';
print(str+(masleep-masleep%60)/60+':'+str1+masleep%60);