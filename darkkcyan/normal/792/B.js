if (typeof print === 'undefined') print = console.log;
if (typeof readline === 'undefined') readline = (function() {
    var lines = require('fs').readFileSync('/dev/stdin').toString().split('\n');
    var id = 0;
    return function() {return lines[id++];}
})();

var t = readline().split(' ');
var n = +t[0], q = +t[1];
var a = readline().split(' ' ).map(function(x) { return (+x); });

var qu = [], ans = [];
for (var i = -1; ++i < n; ) qu.push(i + 1);

for (var i = -1; ++i < q; ) {
    var k = (a[i]) % qu.length;
    //console.warn(k);
    for (var f = k; f--; ) {
        qu.push(qu[0]);
        qu.shift();
    }
    ans.push(qu.shift());
}
print(ans.join(' '));