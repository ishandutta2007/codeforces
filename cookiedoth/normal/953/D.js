
String.prototype.setCharAt = function(index,chr) {
	if(index > this.length-1) return str;
	return this.substr(0,index) + chr + this.substr(index+1);
}

var a = [[3, 3, 4, 4, 3, 3], [3, 3, 4, 4, 3, 3], [2, 2, 3, 3, 2, 2], [2, 2, 3, 3, 2, 2], [1, 1, 2, 2, 1, 1], [1, 1, 2, 2, 1, 1]];
var x = [];
var len_num = 6;
var wid = 6;
for (var i = 0; i < len_num; ++i) {
    var S = readline();
    x.push(S);
}
var t = [0, 1, 3, 4, 6, 7];
var best = 0;
for (var i = 0; i < len_num; ++i) {
    for (var j = 0; j < wid; ++j) {
        var c = x[i][t[j]];
        if ((a[i][j] > best) && (c == '.'))
            best = a[i][j];
    }
}
for (var i = 0; i < len_num; ++i) {
    var out = 0;
    for (var j = 0; j < wid; ++j) {
        var c = x[i][t[j]];
        if ((a[i][j] == best) && (c == '.')) {
            x[i] = x[i].setCharAt(t[j], 'P');
            out = 1;
            break;
        }
    }
    if (out) break;
}
for (var i = 0; i < len_num; ++i) {
    print(x[i]);
}