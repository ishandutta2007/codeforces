ts="qwertyuiop\
asdfghjkl;\
zxcvbnm,./"
s=gets.chop
dt=gets.chop
(0...dt.length).each{|i| dt[i]=ts[ts.index(dt[i]).to_i+(s=="R"?-1:1)]}
puts dt