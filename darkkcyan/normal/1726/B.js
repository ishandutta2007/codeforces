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
    var out = [];
    for (var testcount = 0; testcount < ntest; ++testcount) {
        var _a = readline().split(' ').map(function (x) { return +x; }), n = _a[0], m = _a[1];
        if (m < n) {
            out.push("NO");
            continue;
        }
        if (n % 2 == 1) {
            out.push("YES");
            out.push("".concat(m - (n - 1)).concat(' 1'.repeat(n - 1)));
            continue;
        }
        if (m % 2 == 1) {
            out.push("NO");
            continue;
        }
        if ((m - (n - 2)) <= 0) {
            out.push("NO");
            continue;
        }
        out.push("YES");
        var t = ((m - (n - 2)) / 2) >> 0;
        out.push("".concat(t, " ").concat(t).concat(' 1'.repeat(n - 2)));
    }
    console.log(out.join('\n'));
}