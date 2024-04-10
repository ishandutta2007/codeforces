;
var inp = [];
var lines;
var lineCounter = 0;
var readline = function () { return lines[lineCounter++]; };
process.stdin.on('data', function (c) { return inp.push(c); });
process.stdin.on('end', function () {
    lines = inp.join('').split('\n');
    myMain();
});
function myMain() {
    var ntest = +readline();
    for (var testcase = 0; testcase < ntest; ++testcase) {
        var n = +readline();
        var a = readline().split(' ').map(function (x) { return +x; });
        var ans = a[n - 1] - a[0];
        for (var i = 0; i < n - 1; ++i) {
            ans = Math.max(ans, a[i] - a[i + 1]);
        }
        for (var i = 1; i < n; ++i) {
            ans = Math.max(ans, a[i] - a[0]);
        }
        for (var i = 0; i < n - 1; ++i) {
            ans = Math.max(ans, a[n - 1] - a[i]);
        }
        console.log(ans);
    }
}